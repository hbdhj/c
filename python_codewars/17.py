# Molecule to atoms
# For a given chemical formula represented by a string, count the number of atoms of each element contained in the molecule and return an object.

def parse_molecule (formula, groupNum=1):
    #print("line 5: "+formula)
    atoms = {}
    elem = ""
    num = ""
    if formula.find('(')>=0 or formula.find('[')>=0:
        for ch in formula:
            if ch =='[' or ch == '(':
                start = formula.find(ch)
                if ch == '[':
                    end = formula.rfind(']')
                if ch == '(':
                    end = formula.rfind(')')
                groupNum = ""
                newEnd = end
                #print(formula[end+1:])
                for ch in formula[end+1:]:
                    if ch.isdigit():
                        groupNum+=ch
                        newEnd+=1
                    else:
                        break
                #print("groupNum = " + groupNum)
                if groupNum == "":
                    groupN = 1
                else:
                    groupN = int(groupNum)
                #subFormula = formula.substr(start, end)
                atoms = mergeAtoms(atoms, parse_molecule(formula[:start]), 1)
                atoms = mergeAtoms(atoms, parse_molecule(formula[start+1:end]), groupN)
                atoms = mergeAtoms(atoms, parse_molecule(formula[newEnd+1:]), 1)
    else:
        #print("line 36")
        items = []
        start = 0
        end = 0
        for i in range(len(formula)):
            if formula[i].isupper():
                if i!=0:
                    end=int(i)
                    #print(formula, start, end, type(start), type(end))
                    items.append(formula[start:end])
                    start=end
        #print("line 46", start, len(formula))
        if start!=len(formula):
            items.append(formula[start:len(formula)])
        #print(items)
        for key, value in atoms.items():
            atoms[key]*=groupNum
        for item in items:
            name = ""
            num = 1
            for i in range(len(item)):
                if item[i].isdigit():
                    name = item[:i]
                    #if len(item[i:])>0:
                    #    num = int(item[i:])

                    #print(name, num)
                    break
            if name=="":
                if item in atoms:
                    atoms[item]+=num
                else:
                    atoms[item]=num
            else:
                if name in atoms:
                    atoms[name]+=num
                else:
                    atoms[name]=num
        #print(atoms)
    return atoms

def mergeAtoms(atom1, atom2, num):
    print(atom1, atom2, num)
    for key, value in atom2.items():
        if key in atom1:
            atom1[key]+=value*num
        else:
            atom1[key]=value*num
    print(atom1)
    return atom1

#print(parse_molecule("H2O"))
#print(parse_molecule("Hg21Ol39"))
#print(parse_molecule("H20O"))
#print(parse_molecule("Mg(OH)2"))
print(parse_molecule("K4[ON(SO3)2]2"))