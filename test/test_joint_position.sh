rostopic pub -1 /arm_controller/position_command  brics_actuator/JointPositions '{positions: [
{joint_uri: arm_joint_1, unit: rad, value: 2.9},
{joint_uri: arm_joint_2, unit: rad, value: 1.1},
{joint_uri: arm_joint_3, unit: rad, value: -2.5},
{joint_uri: arm_joint_4, unit: rad, value: 1.7},
{joint_uri: arm_joint_5, unit: rad, value: 1.5}
]}' 


