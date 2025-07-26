from sys import stdin
n = int(stdin.readline().rstrip()) # 노드의 개수 입력 받음

# 일반트리는 유동적이므로 리스트로 구현
# 이진트리는 클래스로 구현
# 완전이진트리는 리스트로 구현
# 이진탐색트리는 클래스로 구현
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# 1단계: 모든 노드 먼저 생성
tree = {}
tree_info = []

for i in range(n):
    value, l, r = stdin.readline().split()
    tree[value] = Node(value)  # 노드만 생성
    tree_info.append((value, l, r))  # 연결 정보 저장

# 2단계: 연결하기
for value, l, r in tree_info:
    if l != '.':
        tree[value].left = tree[l]
    if r != '.':
        tree[value].right = tree[r]

# 현재 노드가 존재하면 재귀 호출
def preorder(node):
    if node:
        print(node.val, end='')
        preorder(node.left)
        preorder(node.right)    

# 현재 노드가 존재하면 재귀 호출
def inorder(node):
    if node:
        inorder(node.left)
        print(node.val, end='')
        inorder(node.right)

# 현재 노드가 존재하면 재귀 호출
def postorder(node):
    if node:
        postorder(node.left)
        postorder(node.right)
        print(node.val, end='')

preorder(tree['A'])
print()
inorder(tree['A'])
print()
postorder(tree['A'])

