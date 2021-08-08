**1) Escriba una rutina (para ambiente gráfico Windows o Linux) que dibuje un triángulo amarillo del tamaño de la ventana.**

resuelto en ejercicio1.c

**2) Escriba las siguientes definiciones/declaraciones:**
**A) Declaración de un puntero a puntero a entero largo con signo.**
**B) Definición de una la función RESTA, que tome dos enteros largos con signo y devuelva su resta. Esta función debe ser visible en todos los módulos del programa.**
**C) Definición de un caracter solamente visible en el módulo donde se define.**

  A. ``` long int** entero;```  
  B.
    ```
    long int resta(long int number, long int otherNumber){
        return number - otherNumber;
    }
    ```  
  C. ```static char c = 'A';```  

**3) Declare la clase TELEFONO para encapsular una cadena numérica correspondiente a un teléfono. Incluya al menos: Constructor(area, numero), Constructor move y Constructor de Copia; Operador <<, ==, =, long y >>. Implemente el operador >>.**   
Resuelto en telefono.h

**4) Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.**  
ej 5 segunda fecha  


**5) ¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de mantener el programa ‘vivo’ ?**  
ej 10 primera fecha  


**6) Explique qué son los métodos virtuales puros y para qué sirven. De un breve ejemplo donde su uso sea imprescindible.**  

Los metodos virtuales puros son un tipo de metodo virtual y son los que se declaran como ```virtual .... = 0 ```. Estos son metodos abstractos que deben ser implementados por las clases derivadas de la clase que declara dicho metodo virtual puro. Sirven para poder aplicar polimorfismo, para que las distintas clases derivadas tengan un comportamiento distinto al invocarse este metodo. Un ejemplo imprescindile es el caso en el que queremos declarar un metodo sin que exista la definición correspondiente.

**7) Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer nros hexadecimales de 4 símbolos y reemplazarlos por su valor decimal (en texto).**  

resuelto en la fecha 2

**8) ¿Qué es el polimorfismo? Ejemplifique mediante código.**  

Es una propiedad 9en la programacion orientada a objetos) por la cual la misma llamada a función tiene distintos comportamientos dependiendo del tipo del objeto. La unica condicion es que los distintos objetos entiendan el mensaje que se les envia.  
Por ejemplo, si tenemos la clase Figura:

```
class Figura{
  public:
    virtual float area() = 0;
}
```

podemos definir las siguientes clases:

```
class Triangulo: public Figura{
  private:
    float base;
    float altura;
  public:
    float area(){
      return base * altura;
    }
}

class Cuadrado: public Figura{
  private:
    float lado;
  public:
    float area(){
      return lado * lado;
    }
}
```

y luego podemos obtener el area de cualquier objeto que pertenezca a una clase que herede de Figura, y cada uno se comportara distinto.

**9) ¿Qué función utiliza para esperar la terminación de un thread? Ejemplifique mediante código.**  

La funcion que se utiliza es join(). Esta funcion bloquea la ejecucion del hilo que llama a esta funcion hasta que la funcion que se ejecuta en el hilo retorna. Luego de llamar a esta funcion, el hilo se vuelve non-joinable y puede ser destruido de manera segura.

**10) Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la cadena A después de haber duplicado todas las ocurrencias de B..**
**ej.: reemp.exe “El final está aprobado” aprobado -----> El final está aprobado aprobado**

resuelto
