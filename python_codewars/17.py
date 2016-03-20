# Molecule to atoms
# For a given chemical formula represented by a string, count the number of atoms of each element contained in the molecule and return an object.

def parse_molecule (formula, groupNum=1):
    print(formula)
    atoms = {}
    elem = ""
    num = ""
    for ch in formula:
        if ch =='[' or ch == '(':
            start = formula.find(ch)
            if ch == '[':
                end = formula.rfind(']')
            if ch == '(':
                end = formula.rfind(')')
            groupNum = ""
            newEnd = end
            print(formula[end+1:])
            for ch in formula[end+1:]:
                if ch.isdigit():
                    groupNum+=ch
                    newEnd+=1
                else:
                    break
            print("groupNum = " + groupNum)
            #subFormula = formula.substr(start, end)
            atoms = mergeAtoms(atoms, parse_molecule(formula[:start]))
            atoms = mergeAtoms(atoms, parse_molecule(formula[start+1:end], int(groupNum)))
            atoms = mergeAtoms(atoms, parse_molecule(formula[newEnd+1:]))
    items = []
    start = 0
    end = 0
    for i in range(len(formula)):
        if formula[i].isupper():
            if i!=0:
                end=int(i)
                print(formula, start, end, type(start), type(end))
                items.append(formula[start:end])
                start=end
    print(start, len(formula))
    if start!=len(formula):
        items.append(formula[start:len(formula)])
    print(items)
    for key, value in atoms.items():
        atoms[key]*=groupNum
        '''
        if ch.isupper():
            if elem == "":
                elem += ch
            else:
                if elem in atoms.keys():
                    atoms[elem] += 1
                else:
                    atoms[elem] = 1
        elif ch.islower():
            elem += ch
        elif ch.isdigit():
            num += ch
        elif ch=='(' or ch==']':
            print("More handle")
        '''
    return atoms
def mergeAtoms(atom1, atom2):
    for key, value in atom2.items():
        if key in atom1:
            atom1[key]+=value
        else:
            atom1[key]=value
    return atom1

print(parse_molecule("H2O"))
#print(parse_molecule("H20O"))
#print(parse_molecule("Mg(OH)2"))
#print(parse_molecule("K4[ON(SO3)2]2"))