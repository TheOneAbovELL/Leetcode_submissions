class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head:
            return head
        dummy = Node(0, None, head, None)
        prev = dummy
        stack = [head]
        while stack:
            node = stack.pop()
            prev.next = node
            node.prev = prev
            if node.next:
                stack.append(node.next)
            if node.child:
                stack.append(node.child)
                node.child = None 
            prev = node
        real_head = dummy.next
        real_head.prev = None
        return real_head
