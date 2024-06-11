using System;

class Program
{
    static void Main(string[] args)
    {
        // Crear una mascota
        Mascota perro = new Mascota("Max", "Labrador Retriever", 3, 'M');

        // Crear una persona
        Persona persona = new Persona("Juan", "Calle 123", "123456789", 1000);

        // Mostrar información de la mascota y la persona antes de la adopción
        Console.WriteLine("Información antes de la adopción:");
        perro.MostrarInformacion();
        Console.WriteLine();
        persona.MostrarInformacion();
        Console.WriteLine();

        // La persona adopta la mascota
        persona.AdoptarMascota(perro);
        Console.WriteLine();

        // Mostrar información de la mascota y la persona después de la adopción
        Console.WriteLine("Información después de la adopción:");
        perro.MostrarInformacion();
        Console.WriteLine();
        persona.MostrarInformacion();
    }
}
