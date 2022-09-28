using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace Serialization
{
    [Serializable]
    class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }

        public Person(string name, int age)
        {
            Name = name;
            Age = age;
        }

        public virtual void Print() => Console.Write($"Имя: {Name} --- Возраст: {Age}");
    }

    [Serializable]
    class Professor : Person
    {
        public string Speciality { get; set; }
        public Professor(string name, int age, string speciality)
            : base(name, age)
        {
            Speciality = speciality;
        }
        public override void Print()
        {
            base.Print();
            Console.WriteLine($"--- Специальность: {Speciality}");
         
        }
    }

    [Serializable]
    class Student : Person
    {
        public string Group { get; set; }
        public Student(string name, int age, string group)
            : base(name, age)
        {
            Group = group;
        }
        public override void Print() => Console.WriteLine($"--- Группа: {Group}");
    }

    class Program
    {
        static void Main(string[] args)
        {
            // объект для сериализации
            Person person = new Person("Tom", 29);
            Professor professor = new Professor("ProfessorName", 59, "Programming");
            Student student = new Student("StudentName", 59, "329/3");
            Console.WriteLine("Объекты созданы");
            Person[] people = new Person[] { person, professor, student };
            // создаем объект BinaryFormatter
            BinaryFormatter formatter = new BinaryFormatter();
            // получаем поток, куда будем записывать сериализованный объект
            using (FileStream fs = new FileStream("people.txt", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, people);

                Console.WriteLine("Объекты сериализованы");
            }

            // десериализация из файла people.dat
            using (FileStream fs = new FileStream("people.txt", FileMode.OpenOrCreate))
            {
                Person[] deserilizePeople = (Person[])formatter.Deserialize(fs);

                foreach (Person p in deserilizePeople)
                {
                    p.Print();
                }

                Console.WriteLine("Объекты десериализованы");
            }

        }
    }
}