from bs4 import BeautifulSoup
import re
page = 0

while True:
    try:
        f = open(f"./downloaded_pages/pagina{page}.html", "r")
    except:
        break

    lines = f.readlines()
    f.close()

    pageText = BeautifulSoup("".join(lines), 'html.parser').getText()

    words = re.split('\W+', pageText)

    outFile = open(f"./words/pagina{page}.html", "w")
    outFile.write(" ".join(words))
    outFile.close()

    page += 1
