void integratelumi_special_input(){
    
	ULong64_t run_nb_previous = 0;
//	 int k=0;
  TString input_tstring ="/cmsuf/data/store/user/t2/users/neha.rawal/CSC_2017_data_RAW_RECO/2017F/dataset_2017F.root";
//	std::cout<<" input string "<<input_tstring<<std::endl;
	TFile *file = TFile::Open(input_tstring);
  ofstream run_list;
	run_list.open("run_checking_F_delievered_input.txt");

  TDirectory *dire = (TDirectory*) file->Get("cscRootMaker");
	TTree *tree = (TTree*) dire->Get("Events");
	ULong64_t Run;
	ULong64_t Event;
	tree->SetBranchAddress("Run",&Run);
	tree->SetBranchAddress("Event",&Event);
	int entries  = tree->GetEntries();
/*	int run_302473 = 0;
	int run_302472 = 0;
	int run_302448 = 0;
	int run_302484 = 0; */
/*if(run ==  305636) return 38510.44831194287;                                                                                                                       
if(run ==  305766) return 38787.189561460786;                                                                                                                      
if(run ==  305809) return 38835.96063687327;                                                                                                                       
if(run ==  305814) return 39305.725777717125;                                                                                                                       */
	int run_305636 = 0;
	int run_305766 = 0;
	int run_305809 = 0;
	int run_305814 = 0;
	
	// run_list<<"entries in individual file :"<<entries<<std::endl; 
//  run_list<<" file name "<<tp<<std::endl;

	for(int i=0; i< entries ; i++){
	//for(int i=0; i< 1000 ; i++){
   tree->GetEntry(i);
     if( Run == 305636 ) {
			 run_305636 +=1;
		 }	
	     if( Run == 305766 ) {
			 run_305766 +=1;
		 }	
		     if( Run == 305809 ) {
			 run_305809 +=1;
		 }	
			     if( Run == 305814 ) {
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
