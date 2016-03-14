import threading
import sys
import configparser

from queue import Queue

from spider import Spider
from domain import *
from general import *

config = configparser.RawConfigParser()
#config.read('bbcnews.ini')
config.read(sys.argv[1])

try:
    PROJECT_NAME = config.get('PROJECT', 'PROJECT_NAME')
    HOMEPAGE = config.get('PROJECT', 'HOMEPAGE')
    CLASS = config.get('PROJECT', 'CLASS')
    SUFFIX = config.get('PROJECT', 'SUFFIX')
except:
    print("Error: get an exception when load configuration file " + sys.argv[1])
    SUFFIX = ""
print(SUFFIX)
DOMAIN_NAME = get_domain_name(HOMEPAGE)
QUEUE_FILE = PROJECT_NAME + '/queue.txt'
CRAWLED_FILE = PROJECT_NAME + '/crawled.txt'
NUMBER_OF_THREADS=int(config.get('DEFAULT', 'NUMBER_OF_THREADS'))

# the thread queue
queue = Queue()

# First spider for the home page
Spider(PROJECT_NAME, HOMEPAGE, DOMAIN_NAME, CLASS, SUFFIX)

# Create a worker thread (will die when main exists)
def create_workers():
    for _ in range(NUMBER_OF_THREADS):
        t = threading.Thread(target=work)
        t.daemon = True
        t.start()

# Do the next job in the queue
def work():
    while True:
        url = queue.get()
        Spider.crawl_page(threading.current_thread().name, url)
        queue.task_done()

# Each queued link is a new job
def create_jobs():
    for link in file_to_set(QUEUE_FILE):
        queue.put(link)
    queue.join()
    crawl()

# Check if there are items in the queue, if so crawl them
def crawl():
    queued_links = file_to_set(QUEUE_FILE)
    if len(queued_links) > 0:
        print(str(len(queued_links)) + ' links in the queue')
        create_jobs()

create_workers()
crawl()