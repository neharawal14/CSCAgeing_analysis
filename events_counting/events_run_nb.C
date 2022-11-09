// this program is to find the number of events inside a run number and store the result into a output text file

void events_run_nb(){
	 TFile *file = TFile::Open("/cmsuf/data/store/user/t2/users/neha.rawal/CSC_2017_data_RAW_RECO/2017B/dataset_2017B.root");
   ofstream run_list;
	 run_list.open("run_events/run_events_2017B_new_dataset.txt");
    
	 int total_entries_per_run =0;
	ULong64_t run_nb_previous = 0;
	 int k=0;
	TDirectory * direc = (TDirectory*) file->Get("cscRootMaker");
	TTree *tree = (TTree*) direc->Get("Events");
	
	ULong64_t Run;
	ULong64_t Event;
	tree->SetBranchAddress("Run",&Run);
	tree->SetBranchAddress("Event",&Event);
	int entries  = tree->GetEntries();
	
	// run_list<<"entries in individual file :"<<entries<<std::endl; 
//  run_list<<" file name "<<tp<<std::endl;
  int flag =0;

	//for(int i=0; i< entries ; i++){
	for(int i=0; i< 100000 ; i++){
   tree->GetEntry(i);
	 if(run_nb_previous!=Run) { total_entries_per_run = 0;
		  run_list<<" entries in run number "<<Run<<" : ";}
//	 if(run_nb_previous ==0) {run_list<<Event<<"\t"; }
   if(run_nb_previous == Run) {
		 total_entries_per_run = total_entries_per_run+1;
		 }
    run_nb_previous = Run; 
	 if(run_nb_previous!=Run && run_nb_previous!=0)  run_list<<total_entries_per_run<<std::endl;
	}
//	std::cout<<" Get number of entries for file "<<input_string<<"entries :"<<entries<<std::endl;
			run_list<<"total number of entries  B my file : "<<entries<<std::endl;
      run_list.close(); //close the file object.
  }
