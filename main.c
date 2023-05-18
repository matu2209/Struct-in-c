#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
    int registration;
    char name[40];
    char gender;
} stStudents;

int chargeStudents(stStudents array[], int dimension);
int searchStudentForRegistration(stStudents array[], int validate, int registration);
int insertStudent(stStudents array[], int validate, stStudents dato);
int countStudentsByGender(stStudents array[], int validate, char gender);

void printStudents(stStudents array[], int validate);
void printOneStudent(stStudents array[], int position);
void orderStudentsByRegistration(stStudents array[], int validate);
void orderStudentsByName(stStudents array[], int validate);
void printStudentsByGender(stStudents array[], int validate, char gender);

int main (){

    stStudents students[50], dato; int dim = 50, validate=-1, numberRegister, numberByGender; char option, gender;

    system("cls");
    do
    {
        printf("\nMenu de opciones\n\n",80);
        printf("1 - Cargar alumnos\n");
        printf("2 - Mostrar los alumnos\n");
        printf("3 - Buscar un alumno por su matricula\n");
        printf("4 - Ordenar los alumnos por su legajo\n");
        printf("5 - Mostrar los alumnos por un genero\n");
        printf("6 - Agregar un alumno\n");
        printf("7 - Ordenar los alumnos por nombre\n");
        printf("8 - Cantidad de alumnos por genero\n");
        printf("\nPara finalizar el programa presione 'esc'\n");
        option = getch();
        system("cls");
        switch (option)
        {
            case '1':
                validate = chargeStudents(students, dim);
            break;
            case '2':
                if (validate != -1)
                    printStudents(students, validate);
                else
                    printf("\nEl arreglo de alumnos esta vacio");
                system("pause");
            break;
            case '3':
                printf("Ingrese un numero de matricula para ser buscado en la base de datos de alumnos: ");
                scanf("%d", &numberRegister);
                numberRegister = searchStudentForRegistration(students, validate, numberRegister);
                if(numberRegister != -1)
                    printOneStudent(students,numberRegister);
                else    
                    printf("\nNo se encontro ningun alumno con esa matricula!");
                system("pause");
            break;
            case '4':
                if (validate != -1){
                    orderStudentsByRegistration(students, validate);
                    printStudents(students,validate);
                } else  
                    printf("\nEl arreglo de alumnos esta vacio");
                system("pause");
            break;
            case '5':
                if (validate != -1){
                    printf("\nIngrese un genero para realizar el filtro: ");
                    fflush(stdin);
                    scanf("%c", &gender);
                    printStudentsByGender(students, validate, gender);
                } else
                    printf("\nEl arreglo de alumnos esta vacio");
                system("pause");
            break;
            case '6':
                if (validate != -1)
                {
                    printf("\nTiene que ingresar los datos del alumno para ser cargado");
                    printf("\nIngrese numero de matricula: ");
                    scanf("%d", &dato.registration);
                    printf("\nIngrese nombre y apellido del alumno: ");
                    fflush(stdin);
                    gets(dato.name);
                    printf("\nIngrese genero F/M: ");
                    fflush(stdin);
                    scanf("%c", &dato.gender);
                    orderStudentsByRegistration(students,validate);
                    validate = insertStudent(students, validate, dato);
                    printf("\nalumno cargado con exito!\n");
                } else  
                    printf("\nEl arreglo de alumnos esta vacio");
                system("pause");
            break;
            case '7':
                if (validate != -1){
                    orderStudentsByName(students, validate);
                    printStudents(students,validate);
                }
                else 
                    printf("\nEl arreglo de alumnos esta vacio");
                system("pause");
            break;
            case '8':
                if (validate != -1)
                {
                    printf("\nIngrese un genero para ser contado los alumnos siendo F/M: ");
                    scanf(" %c", &gender);
                    numberByGender = countStudentsByGender(students, validate, gender);
                    printf("\nLos cantidad de alumnos del genero %c son: %d", gender, numberByGender);
                } else
                    printf("\nEl arreglo alumnos esta vacio");
                system("pause");
            break;
        default:
            break;
        }
        system("cls");
    } while (option != 27);
    
    return 0;

}

/*Carga alumnos a criterio del usuario*/
int chargeStudents(stStudents array[], int dimension){
    int i=0; char option;
    do{
        printf("Ingrese legajo del alumno: ");
        scanf("%d", &array[i].registration);
        printf("\nIngrese nombre y apellido del alumno: ");
        fflush(stdin);
        gets(array[i].name);
        printf("\nIngrese genero del alumno siendo F/M ");
        fflush(stdin);
        scanf("%c", &array[i].gender);
        puts("Esc para salir de la carga");
        option = getch();
        i++;
    } while (i<dimension && option != 27);

    return i;
}

/*muestra los alumnos del arreglo cargado*/
void printStudents(stStudents array[], int validate){
    int i=0; 
    for (i = 0; i < validate; i++)
    {
        printf("\nAlumno: %s", array[i].name);
        printf("\nLegajo: %d", array[i].registration);
        printf("\nGenero: %c", array[i].gender);
        printf("\n");
    }
}

/*busca un alumno por su matricula*/
int searchStudentForRegistration(stStudents array[], int validate, int registration){
    int i=0, position = -1;

    for (i = 0; i < validate; i++)
    {
        if (array[i].registration == registration){
            position = i;
        }
    }
    return position;
}

void printOneStudent(stStudents array[], int position){
    printf("\nAlumno: %s", array[position].name);
    printf("\nLegajo: %d", array[position].registration);
    printf("\nGenero: %c", array[position].gender);
    printf("\n");
}

/*Ordenar por seleccion y por matricula*/
void orderStudentsByRegistration(stStudents array[], int validate){
    int i=0, j=0; stStudents aux;

    for (i = 0; i < validate-1; i++)
    {
        for (j = i+1; j <validate; j++)
        {
            if(array[i].registration > array[j].registration ){
                aux = array[i];
                array[i]=array[j];
                array[j] = aux;
            }
        }
    }
}

/*mostrar los alumnos por genero*/
void printStudentsByGender(stStudents array[], int validate, char gender){

    int i=0;

    for (i = 0; i < validate; i++)
    {
        if (array[i].gender == gender)
            printOneStudent(array, i);
    }
}

/*Insertar estudiante en el arreglo ordenado por legajo*/
int insertStudent(stStudents array[], int validate, stStudents dato){

    int i=validate-1;

    while (array[i].registration > dato.registration && i>=0)
    {
        array[i+1] = array[i];
        i--;
    }
    
    array[i+1] = dato;

    return validate+1;
}

/*ordenar por nombre*/
void orderStudentsByName(stStudents array[], int validate){

    int i, j; stStudents aux;

    for (i = 0; i < validate; i++)
    {
        aux = array[i];
        j = i-1;
        while (strcmp(array[j].name,aux.name)>0 && j>=0)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;        
    }
}

/*contar los alumnos de un genero determinado*/
int countStudentsByGender(stStudents array[], int validate, char gender){
    int i=0, count = 0 ;

    for (i = 0; i < validate; i++)
    {
        if (array[i].gender == gender)
            count++;
    }

    return count;
}
