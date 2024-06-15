#esphome compile esphome.yaml && esphome upload --device /dev/ttyACM0 esphome.yaml && 
esphome run --device /dev/ttyACM0 esphome.yaml
#mosquitto_pub -h broker.hivemq.com -p 1883 -t "esphome/BTHomeReceiverBaseHub/config" -f test_payload.json
