Pseodocode: Vivian
START Vivian's Biomedical Device

// Setup phase
Initialize BUZZER
Initialize Heartrate Sensor

// Main loop
WHILE Power is ON:
    Read Heartrate Sensor
    IF Heartbeat is Detected THEN:
        // Trigger alert sequence
        BEGIN Alert
            Turn BUZZER ON
        END Alert
    ELSE:
        // Continue monitoring
        Loop back to Read Heartrate Sensor

END

Pseodocode: Michelle

BEGIN Michelle's Life Relaxer

// Setup phase
Initialize Heartbeat Sensor
Initialize Speaker
Initialize Button

// Main loop
WHILE Power is ON:
    Read Heartbeat Sensor
    IF Heartbeat is Detected THEN:
        // Continue monitoring
        Loop back to WHILE Power is ON
    ELSE:
        // No heartbeat detected
        Speaker Alert Sequence
        WHILE Button is NOT Pressed:
            // Wait for user intervention
            Loop back to Speaker Alert Sequence
        IF Button is Pressed THEN:
            BEGIN Speaker Alert
                Turn Speaker ON
                PLAY "No Heartrate Detected"
            END Speaker Alert

END