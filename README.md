<h2>ESP32 to Raspberry Pi Pico 2 W I2C Communication</h2>

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

<img width="752" height="507" alt="esptopico" src="https://github.com/user-attachments/assets/e3b1ec80-0ae6-4e78-ac22-cd2e65ba6f81" />

<p>Connect the boards as follows:</p>

<pre><code>ESP32 GPIO21 (SDA) -&gt; Pico GP20
ESP32 GPIO22 (SCL) -&gt; Pico GP21
ESP32 GND          -&gt; Pico GND
</code></pre>

<p>
Pull-up resistors were added from SDA to 3.3V and from SCL to 3.3V to keep the I2C lines stable.
Both boards use 3.3V logic, so no level shifter was needed in this setup.
</p>

<h3>Setting Up the Pico 2 W in Arduino IDE</h3>

<p>
The Pico 2 W can be programmed from the Arduino IDE using the Arduino-Pico core, which supports
both RP2040 and RP2350 boards, including the Pico 2 W. To install it, open Arduino IDE and go to
<b>File &gt; Preferences</b>. In <b>Additional Boards Manager URLs</b>, add:
</p>

<pre><code>https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
</code></pre>

<p>
After that, open <b>Boards Manager</b>, search for <b>pico</b>, and install
<b>Raspberry Pi Pico/RP2040/RP2350 by Earle F. Philhower, III</b>. Then select
<b>Raspberry Pi Pico 2 W</b> from the board list before uploading your sketch. :contentReference[oaicite:0]{index=0}
</p>

<p>
If the board does not show up normally for upload, hold the <b>BOOTSEL</b> button while plugging
the Pico 2 W into USB. It should appear as a removable drive, which lets you load firmware in UF2
mode when needed. :contentReference[oaicite:1]{index=1}
</p>

<h3>Setup Notes</h3>

<ol>
  <li>Connect the wiring exactly as shown above.</li>
  <li>Add pull-up resistors on both I2C lines.</li>
  <li>Install ESP32 board support in Arduino IDE if it is not already installed.</li>
  <li>Install Pico 2 W board support using the Arduino-Pico package.</li>
  <li>Select the correct board and COM port for each device before uploading.</li>
  <li>Upload the ESP32 program to the ESP32 board.</li>
  <li>Upload the Pico program to the Raspberry Pi Pico 2 W.</li>
  <li>Open the serial monitor for the Pico to verify that data is being received correctly.</li>
</ol>

<h3>Project Files</h3>

<ul>
  <li><b>master.cpp.ino</b> - ESP32 master code</li>
  <li><b>pico.ino</b> - Raspberry Pi Pico 2 W slave code</li>
</ul>

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
