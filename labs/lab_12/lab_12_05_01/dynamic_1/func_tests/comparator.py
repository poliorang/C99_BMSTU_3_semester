import sys

def main():
    if len(sys.argv) > 1:
        f_one = sys.argv[1]
        f_two = sys.argv[2]
        with open (f'{f_one}') as f1:
            elems = f1.readlines()

            for i in range(len(elems)):
                elems[i] = elems[i].strip('\n').strip(' ')
            ans_one = ' '.join(elems)

        with open (f'{f_two}') as f2:
            elems = f2.readlines()

            for i in range(len(elems)):
                elems[i] = elems[i].strip('\n').strip(' ')
            ans_two = ' '.join(elems)
        if ans_one.strip('\n').strip(' ') == ans_two.strip('\n').strip(' '):
            print(0)
        else:
            print(1)

if __name__ == "__main__":
    main()
