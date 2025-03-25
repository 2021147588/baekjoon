def solution(n, files):

    extension_dict = {}
    for file in files:
        name, extension = file.split('.')
        if extension not in extension_dict.keys():
            extension_dict[extension] = 1
        else:
            extension_dict[extension]+=1
            
        
    extensions = sorted(extension_dict)

    for i, ex in enumerate(extensions):

        print(ex.rstrip(), extension_dict[ex])

n = int(input())

files = []

for i in range(n):
    temp = input()
    files.append(temp)

solution(n, files)
