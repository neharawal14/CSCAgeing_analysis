chamber=("ME11a" "ME11b" "ME12HV1" "ME12HV2" "ME12HV3" "ME13HV1" "ME13HV2" "ME13HV3" "ME21HV1" "ME21HV2" "ME21HV3" "ME22HV1" "ME22HV2" "ME22HV3" "ME22HV4" "ME22HV5" "ME31HV1" "ME31HV2" "ME31HV3" "ME32HV1" "ME32HV2" "ME32HV3" "ME32HV4" "ME32HV5" "ME41HV1" "ME41HV2" "ME41HV3" "ME42HV1" "ME42HV2" "ME42HV3" "ME42HV4" "ME42HV5")
for chamber_number in ${chamber[@]}; do
	echo $chamber_number
  hadd 2017_all_delievered/DUMMYFILENAME_2017_all_${chamber_number}_tree.root 2017B_delievered/DUMMYFILENAME_B${chamber_number}_tree.root 2017C_delievered/DUMMYFILENAME_C${chamber_number}_tree.root 2017D_delievered/DUMMYFILENAME_D${chamber_number}_tree.root 2017E_delievered/DUMMYFILENAME_E${chamber_number}_tree.root 2017F_delievered/DUMMYFILENAME_F${chamber_number}_tree.root 
done
