# Lab2 OpenPLC Equipo Relay

![WhatsApp Image 2025-10-26 at 8 46 33 PM](https://github.com/user-attachments/assets/d11b2bb8-6f4a-47f5-bee7-cf4df8c5003d)

## Escenario

Una empresa de logística quiere implementar una grúa para mover paquetes pesados en su galpón. Por ello se comunica con la Startup Relay para que implemente el sistema de control de movimiento de la misma.
Inicialmente la grúa está apagada. Un operador enciende el sistema enviando una señal IR, un relé activará el motor de la grúa y empezará a funcionar en modo automático. Mientras la grúa funciona de este modo, el LED de estado (manual o automático) estará apagado y la bocina sonará intermitentemente por 0,5 seg cada 2,5 seg.

Para cambiar el modo de funcionamiento de automático a manual o viceversa, el joystick de la grúa consta de un switch. Una vez en modo manual, un LED se encenderá y el operador podrá manipular el movimiento de la grúa en el eje horizontal y vertical.
Para evitar movimientos bruscos el joystick tiene una zona muerta entre los intervalos x = [400; 600], y = [400; 600]. Solo habrá movimiento cuando los valores de posición estén por fuera de alguno de esos intervalos. El operador sabrá que hay movimiento porque la bocina sonará intermitentemente por 0,5 seg cada 1 seg cuando esté fuera de la zona muerta.

Finalmente, para apagar el sistema se envía una nueva señal IR. El relé dejará de alimentar el motor de la grúa, el LED se apagará, y la bocina dejará de sonar. La próxima vez que se encienda el sistema, estará nuevamente en el último modo de funcionamiento que se haya usado antes de apagarlo.

