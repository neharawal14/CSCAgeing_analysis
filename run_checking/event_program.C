void event_program(){
    
	ULong64_t run_nb_previous = 0;
//	 int k=0;
  TString input_tstring ="/cmsuf/data/store/user/t2/users/neha.rawal/CSC_2017_data_RAW_RECO/nTuple_output/2017/2017D/DUMMYFILENAME_2017D_combined_tree.root";
//	std::cout<<" input string "<<input_tstring<<std::endl;
	TFile *file = TFile::Open(input_tstring);

	TTree *tree = (TTree*) file->Get("tree");
	ULong64_t _runNb;
	double _integratelumi;
	tree->SetBranchAddress("_runNb",&_runNb);
	int entries  = tree->GetEntries();
	
	// run_list<<"entries in individual file :"<<entries<<std::endl; 
//  run_list<<" file name "<<tp<<std::endl;

	//for(int i=0; i< entries ; i++){
	for(int i=0; i< 1000 ; i++){
   tree->GetEntry(i);
     if(_runNb ==302448 || _runNb==302472 || _runNb == 302474)
      { 
				std::cout<<"run_nb"<<_runNb<<" integrate lumi "<<_integratelumi<<std::endl;
		 } 
	}
			std::cout<<"total number of entries "<<entries<<std::endl; 
  }
