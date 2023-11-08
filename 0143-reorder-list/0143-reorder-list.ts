/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

/**
 Do not return anything, modify head in-place instead.
 */
function reorderList(head: ListNode | null): void {
  let [slow, fast] = [head, head];

  while (fast?.next) {
    fast = fast.next.next;
    slow = slow.next;
  }

  let [first, second] = [head, reverseList(slow)];

  while (second.next) {
    const [temp1, temp2] = [first.next, second.next];
    first.next = second;
    first = temp1;

    second.next = first;
    second = temp2;
  }
};

function reverseList(head: ListNode | null): ListNode | null {
  if (!head?.next) return head;
  
  const last = reverseList(head.next);
  head.next.next = head;
  head.next = null;

  return last
}