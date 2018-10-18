import UIKit

var str = "Hello, playground"

22 / 7
28%10
(28.8).truncatingRemainder(dividingBy: 10.0)
1<<3
32>>2


protocol A {
    var num: Int { get }
}

protocol B {
    var count: Int { get }
}

struct C: A {
    var num: Int
    
    mutating func add(_ t: Int) {
        self.num += t
    }
}

var c = C(num: 3)
print(c.num)
c.add(3)
print(c.num)
