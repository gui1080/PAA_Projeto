import time
from bs4 import BeautifulSoup
import re


def index(dict):
    logFile = open("index.log", "a")
    page = 0

    while 1:
        try:
            f = open("./downloaded_pages/pagina" + str(page) + ".html", "r")
        except:
            return
        lines = f.readlines()
        soup = BeautifulSoup("".join(lines), 'html.parser')

        words = re.split('\W+', soup.getText())

        for w in words:
            print(page, w)
            word = w.lower()
            if word in dict:
                if dict[word][-1] != page:
                    dict[word].append(page)
            else:
                dict[word] = [page]

        page = page + 1

    logFile.close()
