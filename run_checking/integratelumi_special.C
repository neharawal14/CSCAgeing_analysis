void integratelumi_special(){
    
	ULong64_t run_nb_previous = 0;
//	 int k=0;
  TString input_tstring ="/cmsuf/data/store/user/t2/users/neha.rawal/CSC_2017_data_RAW_RECO//nTuple_output/2017/2017F_delievered/DUMMYFILENAME_FME12HV1_tree.root";
//	std::cout<<" input string "<<input_tstring<<std::endl;
	TFile *file = TFile::Open(input_tstring);
  ofstream run_list;
	run_list.open("run_checking_F_delievered_ME12HV1.txt");

	TTree *tree = (TTree*) file->Get("tree");
	ULong64_t _runNb;
	double _integratelumi;
	tree->SetBranchAddress("_runNb",&_runNb);
	tree->SetBranchAddress("_integratelumi",&_integratelumi);
	int entries  = tree->GetEntries();
/*	int run_302473 = 0;
	int run_302472 = 0;
	int run_302448 = 0;
	int run_302484 = 0; */
	int run_305636 = 0;
	int run_305766 = 0;
	int run_305809 = 0;
	int run_305814 = 0;
	
	// run_list<<"entries in individual file :"<<entries<<std::endl; 
//  run_list<<" file name "<<tp<<std::endl;

	for(int i=0; i< entries ; i++){
	//for(int i=0; i< 1000 ; i++){
   tree->GetEntry(i);
     if( _runNb == 305636 ) {
			 run_305636 +=1;
		 }	
	     if( _runNb == 305766 ) {
			 run_305766 +=1;
		 }	
		     if( _runNb == 305809 ) {
			 run_305809 +=1;
		 }	
			     if( _runNb == 305814 ) {
			 run_305814 +=1;
		 }	
		//			std::cout<<"run_nb"<<_runNb<<" integrate lumi "<<_integratelumi<<std::endl;
	} std::cout<<"total number of entries "<<entries<<std::endl; 
	//		std::cout<<" entries 302473 : "<<run_302473<<std::endl;
//			std::cout<<" entries 302472 : "<<run_302472<<std::endl;
//			std::cout<<" entries 302448 : "<<run_302448<<std::endl;
			//std::cout<<" entries 302484 : "<<run_302484<<std::endl;

			std::cout<<" entries 305636 : "<<run_305636<<std::endl;
			std::cout<<" entries 305766 : "<<run_305766<<std::endl;
			std::cout<<" entries 305809 : "<<run_305809<<std::endl;
			std::cout<<" entries 305814 : "<<run_305814<<std::endl;

//			run_list<<" entries 302473 : "<<run_302473<<std::endl;
//			run_list<<" entries 302472 : "<<run_302472<<std::endl;
//			run_list<<" entries 302448 : "<<run_302448<<std::endl;
//			run_list<<" entries 302484 : "<<run_302484<<std::endl;
			run_list<<" entries 305636 : "<<run_305636<<std::endl;
			run_list<<" entries 305766 : "<<run_305766<<std::endl;
		run_list<<" entries 305809 : "<<run_305809<<std::endl;
			run_list<<" entries 305814 : "<<run_305814<<std::endl;


  }
