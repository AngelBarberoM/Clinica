# Nueva Cita

**Identificación**: 2

**Descripción**: Se introduce el día, mes, hora de comienzo y el tiempo de la cita. Se asigna la cita al paciente conrrespondiente que acudirá a esta.

**Principal**: Clínica

**Condición para desarrollar esta tarea**:

* Seleccionar previamente a un paciente.

**Flujo principal**:

1. El administrador de la clínica concerta una cita con un paciente.
2. El administrador de la clínica selecciona el paciente correspondiente.
3. El administrador de la clínica elige la opcion de concertar cita.
4. El administrador de la clínica introduce los datos de la cita.
5. El sistema añade la cita al paciente.

**Condiciones inesperadas**:

5.a. Si los datos de la cita se introducen incorrectamente, no se añade y se muestra un mensaje de error.
5.b. Si la cita se solapa con otra ya existente se mostrará un mensaje de confirmación antes de añadirla.
