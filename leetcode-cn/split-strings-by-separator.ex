defmodule Solution do
  @spec split_words_by_separator(words :: [String.t], separator :: char) :: [String.t]
  def split_words_by_separator(words, separator) do
    words |> Enum.flat_map(&(String.split(&1, <<separator>> |> to_string))) |>
Enum.map(&(String.trim(&1))) |> Enum.filter(&(&1 != ""))
  end
end