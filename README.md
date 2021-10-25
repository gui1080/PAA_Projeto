# Projeto de Disciplina PAA

## Como rodar

É necessário ter o scrapy instalado e ser capaz de executá-lo. Numa máquina linux roda

```
make install
```

Em seguida para rodar o web-crawler usa-se

```
scrapy runspider scrapy/scraper.py
```


## Participantes

Alunos:

Carlos Eduardo Taborda Lottermann - 18/0041509

Gabriel Delolmo Erhardt - 17/0142612

Guilherme Braga Pinto - 17/0162290


## Funcionamento do Webcrawler

A partir da biblioteca Scrapy, utilizou-se um Webcrawler para, a partir de uma lista de links, realizar o download de páginas fonte html.

Essas páginas, agora salvas localmente e salvas em uma lista separadamente, foram usadas para a busca por meio de árvore rubro-negra.

A implementação do indexador e pesquisador foi feita em c++.

## Link do Projeto no Github

https://github.com/gui1080/PAA_Projeto_Google2
