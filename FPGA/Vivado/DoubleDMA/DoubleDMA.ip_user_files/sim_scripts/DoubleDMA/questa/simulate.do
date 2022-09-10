onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib DoubleDMA_opt

do {wave.do}

view wave
view structure
view signals

do {DoubleDMA.udo}

run -all

quit -force
