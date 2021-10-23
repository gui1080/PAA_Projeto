def pega_url_arquivo():
    f = open("initial_links.txt", "r")

    urls = []

    for line in f.readlines():
        print(line)
        urls.append(line)

    f.close()

    return urls


def pega_url():
    try:
        return pega_url_arquivo()
    except:
        pass

    print("Arquivo \"initial_links.txt\" com links iniciais não encontrado!")

    link_inicial = input("Link inicial:\n")

    return [link_inicial]
