import re
def domain_name(url):
    return re.match('(.*//)?(www\\.)?(.*?)\\.',url).group(3)