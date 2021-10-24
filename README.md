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

Gabriel Nardelli Aprá - 18/0046322

Guilherme Braga Pinto - 17/0162290

Rafael Barbosa de Sousa - 17/0043827

## Funcionamento do Webcrawler

A partir da biblioteca Scrapy, utilizou-se um Webcrawler para, a partir de uma lista de links, realizar o download de páginas fonte html com a função "LinkExtractor()". 

Essas páginas, agora salvas localmente e salvas em uma lista separadamente, podem ser usadas para a busca com o uso de uma estrutura de dados por meio de árvore. 

## Link do Projeto no Github

https://github.com/gui1080/PAA_Projeto_Google2
