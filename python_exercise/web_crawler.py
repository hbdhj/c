# follow newboston web crawler lesson
import os

# each website you crawl is a seperate project folder
def create_project_dir(directory):
    if not os.path.exist(directory):
        print("Creating project "+ directory)
        os.makedirs(directory)

# create queue and crawled files (if not created)
def create_data_files(project_name, base_url):
    queue = project_name + 'queue.txt'
    crawled =project_name + 'crawled.txt'
    if not os.path.isfile(queue):
        write_file(queue, base_url)
    if not os.path.isfile(crawled):
        write_file(crawled, '')

#create a new file
def write_file(path, data):
    f = open(path, 'a')
    f.write(data)
    f.close()

# add data to an existing file
def append_to_file(path, data):
    with open(path, 'a') as file:
        file.write(data + '\n')

# delete the contents of a file
def delete_file_content(path):
    with open(path, 'w') :
        pass


# read a file and convert each line to set items
def file_to_set(filename):
    results = set()
    with open(filename, 'rt') as f:
        for line in f:
            results.add(line.replace('\n', ''))
    return results;

# Iterate through a set, each item will be a new line in the file
def set_to_file(links, file):
    delete_file_content(file)
    for link in sorted(links):
        append_to_file(link, file)

