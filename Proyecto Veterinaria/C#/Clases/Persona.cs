using System;
using System.Collections.Generic;

namespace Vete;
public class Persona
{
    // Atributos
    public string Nombre { get; set; }
    public string Direccion { get; set; }
    public string Documento { get; set; }
    public float Saldo { get; set; }
    public List<Mascota> Mascotas { get; set; }

    // Constructor
    public Persona(string nombre, string direccion, string documento, float saldo)
    {
        Nombre = nombre;
        Direccion = direccion;
        Documento = documento;
        Saldo = saldo;
        Mascotas = new List<Mascota>();
    }

    // Método para mostrar información de la persona
    public void MostrarInformacion()
    {
        Console.WriteLine($"Nombre: {Nombre}");
        Console.WriteLine($"Dirección: {Direccion}");
        Console.WriteLine($"Documento: {Documento}");
        Console.WriteLine($"Saldo: ${Saldo}");

        if (Mascotas.Count > 0)
        {
            Console.WriteLine("Mascotas:");
            foreach (var mascota in Mascotas)
            {
                Console.WriteLine($"- {mascota.Nombre}");
            }
        }
        else
        {
            Console.WriteLine("Esta persona no tiene mascotas.");
        }
    }

    // Método para adoptar una mascota
    public void AdoptarMascota(Mascota mascota)
    {
        Mascotas.Add(mascota);
        Console.WriteLine($"{Nombre} ha adoptado a {mascota.Nombre}.");
    }
}