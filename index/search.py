import time


def search(dict):
    time.sleep(0) # cede controle para thread index
    while True:
        time.sleep(0) # cede controle para thread index
        text = input("Entre palavra para pesquisa:\n").lower()

        if text in dict:
            print(dict[text])
