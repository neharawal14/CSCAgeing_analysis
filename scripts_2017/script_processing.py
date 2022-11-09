import os
import subprocess
chamber_list = ["ME13HV1"]
#chamber_list = ["ME21HV1", "ME21HV2", "ME21HV3", "ME22HV1" ,"ME22HV2", "ME22HV3", "ME22HV4", "ME22HV5", "ME31HV1", "ME31HV2", "ME31HV3", "ME32HV1", "ME32HV2", "ME32HV3", "ME32HV4", "ME32HV5", "ME41HV1", "ME41HV2", "ME41HV3", "ME42HV1", "ME42HV2", "ME42HV3", "ME42HV4", "ME42HV5"]
path = "/cmsuf/data/store/user/t2/users/neha.rawal/CSC_2017_data_RAW_RECO/nTuple_output/2017/scripts_2017/"
for chamber in chamber_list:
		
	run_string = "os.system(\"root -l -b -q \\\'macro_running.C(\\\"DUMMYFILENAME_2017_all_{}_tree\\\",\\\"{}\\\")\\\'\")".format(chamber,chamber)
	f1 = open("processing_{}.py".format(chamber),"w")
	f1.write("import os\n")
	f1.write(run_string)
	f1.close()
	f = open("job_{}.batch".format(chamber),"w")
	f.write("#!/bin/bash\n")
	f.write("#SBATCH --job-name=myjob\n")
	f.write("#SBATCH --output=myjob_output_{}.log\n".format(chamber))
	f.write("#SBATCH --error=myjob_error_{}.log\n".format(chamber))
	f.write("#SBATCH --mem=32gb\n")
	f.write("#SBATCH --time=3:00:00\n")
	f.write("#SBATCH --account=avery\n")
	f.write("#SBATCH --mail-user=neha.rawal@ufl.edu\n")
	f.write("#SBATCH --mail-type=ALL\n")
	f.write("python {}processing_{}.py >> output_{}.txt\n".format(path,chamber,chamber))
	f.close()

	subprocess.call("sbatch job_{}.batch".format(chamber),shell=True)
