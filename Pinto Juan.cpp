#include <stdio.h>

#define CLASES 4
#define HORARIOS 5

int main() {
    int cupo[CLASES] = {20, 20, 20, 20};
    int asistencia[CLASES][HORARIOS] = {0};
    char clases[CLASES][20] = {"Top Ride", "Zumba", "Entrenamiento", "Abdominales"};
    int totalAsistentes = 0;
    int gananciaTotal = 0;

    int horario, clase;
    int hayHorarioVacio = 0;
    int hayClaseSinAsistentes = 0;

    // Registro de asistencia
    for (horario = 0; horario < HORARIOS; horario++) {
        printf("Horario %d:\n", horario + 1);

        int hayCupo = 0; // Variable para verificar si hay cupo en algún horario

        for (clase = 0; clase < CLASES; clase++) {
            int asistentes;

            printf("Ingrese la cantidad de participantes para la clase %s: ", clases[clase]);
            scanf("%d", &asistentes);

            // Verificar si hay cupo en la clase
            if (asistentes <= cupo[clase]) {
                asistencia[clase][horario] = asistentes;
                cupo[clase] -= asistentes;
                totalAsistentes += asistentes;
                gananciaTotal += asistentes * ((horario == 2) ? 700 : (horario < 2) ? 700 * 0.8 : 700 * 1.15);

                hayCupo = 1;
            } else {
                printf("No hay cupo suficiente para la clase '%s' en este horario.\n", clases[clase]);
            }
        }

        if (!hayCupo)
            hayHorarioVacio = 1;
    }

    // Informar la clase sin asistentes
    printf("\nClase sin participantes:\n");
    for (clase = 0; clase < CLASES; clase++) {
        int asistentesClase = 0;
        for (horario = 0; horario < HORARIOS; horario++) {
            asistentesClase += asistencia[clase][horario];
        }

        if (asistentesClase == 0) {
            printf("%s\n", clases[clase]);
            hayClaseSinAsistentes = 1;
        }
    }

    if (!hayClaseSinAsistentes)
        printf("No hay clases sin participantes.\n");

    // Informar el horario sin clases
    printf("\nHorario sin clases:\n");
    for (horario = 0; horario < HORARIOS; horario++) {
        int hayClase = 0;
        for (clase = 0; clase < CLASES; clase++) {
            if (asistencia[clase][horario] > 0) {
                hayClase = 1;
                break;
            }
        }

        if (!hayClase)
            printf("Horario %d\n", horario + 1);
    }

    // Informar la cantidad de personas que asistieron a cada clase
    printf("\nCantidad de personas que asistieron a cada clase:\n");
    for (clase = 0; clase < CLASES; clase++) {
        int totalClase = 0;
        for (horario = 0; horario < HORARIOS; horario++) {
            totalClase += asistencia[clase][horario];
        }
        printf("%s: %d\n", clases[clase], totalClase);
    }

    // Informar la ganancia total
    printf("\nGanancia total: $%d\n", gananciaTotal);

    return 0;
}



