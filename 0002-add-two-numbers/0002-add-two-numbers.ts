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

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const dummy = new ListNode(-1);
    let curr = dummy;
    let hold = 0;

    while (l1 || l2 || hold > 0) {
        const curVal = (l1?.val || 0) + (l2?.val || 0) + hold;
        curr.next = new ListNode(curVal % 10);
        curr = curr.next;
        l1 = l1?.next;
        l2 = l2?.next;
        curVal >= 10 ? hold = Math.floor(curVal / 10) : hold = 0;
    }

    return dummy.next;
};