import xml.etree.ElementTree as ET
import os


# Lidar provisoriamente com a tradução do texto em tex
# para html
# Será substituido posteriormente por uma abordagem
# utilizando expressões regulares
def tex2html(s):
    s = s.replace("\\begin{itemize}", "\n<ul>")
    s = s.replace("\\end{itemize}", "</ul>")
    s = s.replace("\\item", "<br />")
    s = s.replace("\\InputFile", "\n\nEntradas:\n\n")
    s = s.replace("\\OutputFile", "\n\nSaídas:\n\n")
    s = s.replace("\\^", "^")
    s = s.replace("\\ge", "&#8805;")
    s = s.replace("\\geq", "&#8805;")
    s = s.replace("\\leq", "&#8804;")
    s = s.replace("\\le", "&#8804;")
    s = s.replace("$", " ")
    s = s.replace("\\arrowvert", "|")

    return s


# Templates para a questão e para casos teste
tree = ET.parse('Template.xml')
root = tree.getroot()
treetest = ET.parse('Testcase-Template.xml')
roottest = treetest.getroot()

questao = 'ed'

# print(root[0][0][0].text)
# print(root[0][1][0].text)
# print(root[0][21].text)

# A abordagem utilizada para acessar e modificar os elementos do xml
# será substituida por outra que busca-os primeiramente no arquivo
# antes de apenas acessa-los.
with open(questao+'/statement-sections/english/name.tex', 'r') as name:
    root[0][0][0].text = name.read()

with open(questao+'/statements/english/problem.tex', 'r') as texto:
    s = texto.read()
    s = tex2html(s)
    root[0][1][0].text = s

namesolution = 'ed-pilha-infix2posfix.cpp'

with open(questao+'/solutions/' + namesolution, 'r') as sol:
    root[0][21].text = sol.read()

tests = os.listdir(questao+'/tests/')
tests.sort()

for arq in tests:
    if arq.endswith('.a'):
        with open(questao+'/tests/'+arq, 'r') as answer:
            roottest[2][0].text = answer.read()
            root[0][41].append(roottest)
    else:
        with open(questao+'/tests/'+arq, 'r') as testcase:
            roottest[0][0].text = testcase.read()


tree.write('Problem.xml')
