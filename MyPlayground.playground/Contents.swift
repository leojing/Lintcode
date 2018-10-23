import UIKit

var str = "Hello, playground"

let input = " vbdfj bvhdf bbb   bvhdb   "
let newArray = input.split(separator: " ")
newArray.joined(separator: " ")


protocol Person {
    var name: String { get }
    var age: Int { get }
}

enum Teacher: Person {
    case primary
    case highSchool
    case university
    
    var name: String {
        switch self {
        case .primary:
            return "primary"
            
        case .highSchool:
            return "hight school"
            
        case .university:
            return "university"
        }
    }
    
    var age: Int {
        return 20
    }
}

enum Programmer: Person {
    case iOS
    case andriod
    case Java
    
    var name: String {
        switch self {
        case .iOS:
            return "iOS developer"
            
        case .andriod:
            return "android developer"
            
        case .Java:
            return "Jave developer"
        }
    }
    
    var age: Int {
        return 30
    }
}

class Meetup {
    func getInfoFromPerson(_ person: Person) {
        print(person.name + " " + String(person.age))
    }
}

let meetup = Meetup()
meetup.getInfoFromPerson(Teacher.highSchool)
meetup.getInfoFromPerson(Teacher.primary)
meetup.getInfoFromPerson(Programmer.iOS)
meetup.getInfoFromPerson(Programmer.andriod)

