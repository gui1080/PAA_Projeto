from index import index
from search import search
from threading import Thread

dict = {}

index(dict)
search(dict)

# Thread(target=index, args=(dict,)).start()
# Thread(target=search, args=(dict,)).start()
