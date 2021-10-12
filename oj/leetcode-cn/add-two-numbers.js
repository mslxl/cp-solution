//Definition for singly-linked list.
function ListNode(val) {
    this.val = val;
    this.id = val.toString()
    this.next = null;
    this.toString = function(){
        return this.id
    }
}


/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
    let n1 = l2n(l1)
    let n2 = l2n(l2)
    let sum = n1 + n2
    return n2l(sum)
};

function n2l(n) {
    let i = n % 10n
    let l = new ListNode(parseInt(i))

    if (n >= 10n) {
        l.next = n2l(n / 10n)
    }
    return l
}

function l2n(l) {
    let n = BigInt(l.val)
    if (l.next != null)
        n += BigInt(l2n(l.next)) * 10n
    return n
}

(() => {
    $visualize = {
        kind:{
            graph:true
        }
    }

    function printLink(l) {
        process.stdout.write(l.val.toString())
        if (l.next != null) {
            process.stdout.write(" -> ")
            printLink(l.next)
        } else {}
    }
    /**
     * 
     * @param {Array} arr 
     */

    function createLink(arr){
        let l = new ListNode(arr[0])
        let sub = arr.slice(1)
        if(sub.length > 0){
            l.next = createLink(sub)
        }
        return l
    }
    let l1 = createLink([1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1])
    let l2 = createLink([5,6,4])

    let sum = addTwoNumbers(l1, l2)

    printLink(sum)
})()