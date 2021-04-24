text = "my name is methos"


class TreeNode(object):

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

    def children(self):
        return (self.left, self.right)
         
    def __str__(self):
        return '%s_%s' % (self.left, self.right)



def huffman_code(node,h_text=''):
    if type(node) is str:
        return {node: h_text}
    (l_node, r_node) = node.children()
    d = dict()
    d.update(huffman_code(l_node, h_text + '0'))
    d.update(huffman_code(r_node, h_text + '1'))
    return d


# def huffman_decode(node, text):
#     tmp = node
#     res = []

#     #tranverse coded string
#     for char in text:
#         if char == '0':
#             tmp = tmp.left
#         else:
#             tmp = tmp.right

#         # check for a leaf node and go to the top of the tree
#         if tmp.left is None and temp.right is None: 
#             tmp = root

#      print("".join(res))

frequency = {}

for char in text:
    if char in frequency:
        frequency[char] += 1
    else:
        frequency[char] = 1


frequency = sorted(frequency.items(),
                    key=lambda x: x[1],
                    reverse=True)

nodes = frequency


while len(nodes) > 1:
    (l_key, fl) = nodes[-1]
    (r_key, fr) = nodes[-2]
    nodes = nodes[:-2]
    node = TreeNode(l_key, r_key) #the chars actually
    print(node)
    nodes.append((node, fl + fr)) #the frequency of each one    

    nodes = sorted(nodes, 
                    key=lambda x: x[1], 
                    reverse=True)

encoded_tree = huffman_code(nodes[0][0])

print('  char |   code   |  freq')
print('--------------------------------')
for (char, freq) in frequency:
    print(' %4r |%10s |%5s' % (char, encoded_tree[char], freq))

encoded_text = ''.join([encoded_tree.get(c, '') for c in text])

print(nodes[0][0])

print(encoded_text)

