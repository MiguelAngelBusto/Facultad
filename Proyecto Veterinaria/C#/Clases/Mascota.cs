namespace Vet;

public class Mascota
{
    // Atributos
    public string Nombre { get; set; }
    public string Raza { get; set; }
    public int Anios { get; set; }
    public char Sexo { get; set; }

    // Constructor
    public Mascota(string nombre, string raza, int anios, char sexo)
    {
        Nombre = nombre;
        Raza = raza;
        Anios = anios;
        Sexo = sexo;
    }

    // Método para mostrar información de la mascota
    public void MostrarInformacion()
    {
        Console.WriteLine($"Nombre: {Nombre}");
        Console.WriteLine($"Raza: {Raza}");
        Console.WriteLine($"Edad: {Anios} años");
        Console.WriteLine($"Sexo: {Sexo}");
    }
}