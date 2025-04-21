# VITAHELM
Innovativer Helm, der über verschiedene Sensoren Vitalwerte des menschlichen Körpers im Kopfbereich erfasst.

Diese Daten werden verarbeitet und ausgewertet, um die Stimmung des Traegers zu bestimmen. Die Stimmung wird anschließenddurch eine farbige LED-Flosse auf dem Helm visualisiert, sodass sie intuitiv vom Gegenueber erkannt werden kann.

Der VitaHelm soll die Stimmung des Traegers zuverlaessig erkennen und diese visuell durch
eine LED-Flosse signalisieren. Dafuer werden folgende Parameter erfasst:
 • Atemfrequenz: Messung ueber Mikrofone
 • Puls und Sauerstoffsaettigung: Messung ueber Sensoren an der Helminnenseite
 • Augenzustand: Erkennung durch eine Kamera, ob die Augen geoeffnet oder geschlossen sind
 • Pupillenposition: Erfassung der Pupillenbewegung
 • Gesichtsmimik: Analyse der Gesichtsmuskelaktivitaet
 • Neigungs- und Beschleunigungssensoren: Erfassung der Kopfbewegung

Testlaeufe werden unter realen Bedingungen vom Team durchgefuehrt, um die Erfassungund Visualisierung der Stimmungslagen zu validieren. Der Helm wird in verschiedenen Situationen getestet, um die Erkennungsgenauigkeit zu gewaehrleisten.

Bauteilliste: 
 - ESP32 (Microcontroller)
 - Oximeter Sensor (Sauerstoffsaettigung), Pulsmesser
 - Mikrofon (Atemfrequenzmessung)
 - Kamera (Augen- und Gesichtserkennung)
 - Neigungs- und Beschleunigungssensoren (MPU6050)
 - LED-Flosse (fuer Stimmungsanzeige)
 - Helm
