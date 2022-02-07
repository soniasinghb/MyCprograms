//class = A blueprint for creating objects
//        defines properties and/or methods
/*
class Car{
    drive(){
        console.log("You drive the car");
    }
    brake(){
        console.log("You step on the brake");
    }
}

let car = new Car();
let car2 = new Car();

car.drive();
car2.drive();
*/
//***********constructor and this****************
//static = method/property of a class not of any object
/*

class Car{

    static numberofCars=0;
    static beginRace(){
        console.log("The race has begun");
    }
    
    constructor(make,model,year,color){
        this.make= make;
        this.model = model;
        this.year=year;
        this.color=color;
        Car.numberofCars+=1;
    }
    drive(){
        console.log("You drive the car");
    }
    brake(){
        console.log("You step on the brake");
    }
    whatisThis(){
        return this;
    }
}

let car = new Car("Ford","Mustang",2022,"blue");
let car2 = new Car("Skoda","Rapid",2018,"White");
let car3 = new Car("Skoda","Octavia",2018,"Green");

console.log(car2.model);
console.log(car.year);

console.log(car.whatisThis());

console.log(Car.numberofCars);
Car.beginRace();
*/

//******inheritance********* */ 
//extends keyword
//keep ancestor class from which many classes which want similar properties can be inherited
/*
class Animal{
    constructor(){
        this.alive=true;
    }
    eat(){
        console.log("This animal os eating");
    }
}

class Rabbit extends Animal{

}
class fish extends Animal{
    eat(){
        console.log("fish os eating");      //method overriding
    }
}
class hawk extends Animal{

}
let rabbit = new Rabbit();
let fish= new fish();
let hawk=new hawk();

console.log(rabbit.alive);
hawk.eat();
*/


