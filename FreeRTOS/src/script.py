counter = 0

with open('tasks.c') as topo_file:
    for i,line in enumerate(topo_file):
        if '}' in line:
            counter -= 1
        if counter < 0:
            print("Error on line {}".format(i))
            break
        if '{' in line:
            counter += 1
if counter != 0:
    print('ERROR counter={}'.format(counter))