from json import dumps, loads
from os import path, getcwd


##### iterate over three attributes [numb_round, transfor, bit]
## create an object for each one
## make sure the ordering is same as the one in testbench
## create json object
## write it out
NUMBER_OF_ROUNDS = 9
NUMBER_OF_TRANSFORMATION = 3
NUMBER_OF_SELECTED_BITS = 10
NUMBER_OF_DUT_INSTANCES = NUMBER_OF_ROUNDS


test_spec_json_path = "test_spec.json"
obj_type = "signal.sc_logic.1"
function_type = "bit-flip"
function_value = "1"
# injectionTime_start = "15.0"
# injectionTime_end = 0.0

json_obj = dict()
transformations = [
    "subbyte__r_", "shiftrow__r_", 
    "mixcolumn__r_"
]
# extracting data from sheet3: EX
#     create json file
# iterate through each row and select

fault_iter = 0
dut_iter = 0
bit_iter = 0
injectionTime_start_iter = 0

for round_iter in range(NUMBER_OF_ROUNDS):
    injectionTime_start_iter = 0
    for transformation_iter in transformations:
        for bit_iter in range(NUMBER_OF_SELECTED_BITS):
            obj_name = str(transformation_iter + str(round_iter) + "__bit_" + str((bit_iter*20)%128) + "__dut_" + str(dut_iter) + "_")
            json_obj.update({str(fault_iter): 
                {"Object": 
                    {"Name": obj_name, "Type": obj_type}, 
                "Function": 
                    {"Type": function_type, "Value": function_value, "injectionTime_start": float(injectionTime_start_iter+1), "injectionTime_end": float(injectionTime_start_iter+45)}}})
            injectionTime_start_iter = injectionTime_start_iter + 50
            fault_iter = fault_iter + 1
        
    dut_iter = dut_iter + 1

# write json file 
with open(test_spec_json_path, "w") as f:
    f.write(dumps(json_obj))
