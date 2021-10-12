import Control.Applicative
import Data.Char

main :: IO()
main = undefined

newtype Parser a = Parser { runParser:: String -> Maybe (a, String) }

instance Functor Parser where 
    fmap f p = Parser $ \str ->
        case runParser p str of
            Just (a, s) -> Just (f a, s)
            Nothing -> Nothing

instance Applicative Parser where
    pure a = Parser $ \str -> Just (a, str)
    (<*>) fp a = 
        Parser $ \str ->
            case runParser fp str of
                Nothing -> Nothing
                Just (ab, s) ->
                    case runParser a s of
                        Nothing -> Nothing
                        Just (at, s1) -> Just(ab at, s1)

instance Alternative Parser where
    empty = Parser $ const Nothing
    (<|>) a b = Parser $ \str ->
        case runParser a str of
            Nothing -> runParser b str
            just -> just

satisfy :: (Char -> Bool) -> Parser Char
satisfy f = Parser $ \str -> case str of
    [] -> Nothing
    s : ss -> if f s then Just (s, ss) else Nothing

char :: Char -> Parser Char
char c = satisfy (==c)