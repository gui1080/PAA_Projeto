from bs4 import BeautifulSoup
import re

page = 0
while 1:
    try:
        f = open("../downloaded_pages/pagina" + str(page) + ".html","r")
    except:
        break
    lines = f.readlines()
    soup = BeautifulSoup("".join(lines),'html.parser')
    page = page + 1
    print(re.split('\W+',soup.getText()))
