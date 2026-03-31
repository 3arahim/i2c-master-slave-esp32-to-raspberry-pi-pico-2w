# i2c-master-slave-esp32-to-raspberry-pi-pico-2w
<img width="752" height="507" alt="esptopico" src="https://github.com/user-attachments/assets/aa89b9bd-fb06-4d67-a871-f28cd4d281a0" />

<p>
This project shows how to connect an ESP32 to a Raspberry Pi Pico 2 W using I2C communication.
The ESP32 acts as the master device and the Pico 2 W acts as the slave. The goal of this setup
was to build and verify reliable communication between two microcontrollers using shared SDA, SCL,
and ground connections.
</p>

<h3>Overview</h3>

<p>
This was built as a simple embedded communication test between two development boards. The setup
uses standard I2C wiring with pull-up resistors on the data and clock lines. Once connected and
programmed, the ESP32 sends data packets and the Pico receives and prints the values through serial.
</p>

<h3>Hardware Used</h3>

<ul>
  <li>ESP32 development board</li>
  <li>Raspberry Pi Pico 2 W</li>
  <li>Two pull-up resistors for I2C</li>
  <li>Breadboard and jumper wires</li>
</ul>

<h3>Wiring</h3>

<p>Connect the boards as follows:</p>

<pre><code>ESP32 GPIO21 (SDA) -&gt; Pico GP20
ESP32 GPIO22 (SCL) -&gt; Pico GP21
ESP32 GND          -&gt; Pico GND
</code></pre>

<p>
Pull-up resistors were added from SDA to 3.3V and from SCL to 3.3V to keep the I2C lines stable.
Both boards use 3.3V logic, so no level shifter was needed in this setup.
</p>

<h3>Setup Notes</h3>

<ol>
  <li>Connect the wiring exactly as shown above.</li>
  <li>Add pull-up resistors on both I2C lines.</li>
  <li>Upload the ESP32 program to the ESP32 board.</li>
  <li>Upload the Pico program to the Raspberry Pi Pico 2 W.</li>
  <li>Open the serial monitor for the Pico to verify that data is being received correctly.</li>
</ol>

<h3>Expected Result</h3>

<p>
After both boards are powered and programmed, the Pico should receive the transmitted values from
the ESP32 and print them through serial output. This confirms that the I2C link is working and that
the Pico is correctly configured as a slave device.
</p>

<h3>Notes</h3>

<ul>
  <li>Make sure both boards share a common ground.</li>
  <li>Check that SDA and SCL are not swapped.</li>
  <li>Confirm that the slave address matches on both sides.</li>
  <li>If communication fails, check the pull-up resistors first.</li>
</ul>
