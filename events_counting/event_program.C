void event_program(){
   fstream newfile;
   newfile.open("/blue/avery/neha.rawal/CSCAgeingP5/CMSSW_8_0_27/src/CSCAgeingP5/Work/run_list_2017B_new.txt",ios::in);  // open a file to perform write operation using file object
   ofstream run_list;
	 run_list.open("event_number/event_2017B_new_dataset.txt", ios::app);
    
	 int total_entries =0;
	ULong64_t run_nb_previous = 0;
//	 int k=0;
   if (newfile.is_open()){   //checking whether the file is open
      string tp;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
         cout << tp << "\n"; //print the data of the string
      	TString input_tstring = TString(tp);
//	std::cout<<" input string "<<input_tstring<<std::endl;
	TFile *file = TFile::Open(input_tstring);
	TDirectory * direc = (TDirectory*) file->Get("cscRootMaker");

	TTree *tree = (TTree*) direc->Get("Events");
	ULong64_t Run;
	tree->SetBranchAddress("Run",&Run);
	int entries  = tree->GetEntries();
	total_entries = total_entries+entries;
	
	// run_list<<"entries in individual file :"<<entries<<std::endl; 
//  run_list<<" file name "<<tp<<std::endl;
/*
	for(int i=0; i< entries ; i++){
   tree->GetEntry(i);
     if(run_nb_previous == Run) continue;
      else{ 
				std::cout<<"run_nb"<<std::endl;
				run_list<<"run_nb :"<<Run<<std::endl; } 
      run_nb_previous = Run; 
		 } */
//  k = k+1; 
//	if(k==2) break;
	}
//	std::cout<<" Get number of entries for file "<<input_string<<"entries :"<<entries<<std::endl;
  }
			run_list<<"total number of entries  B my file : "<<total_entries<<std::endl;
      newfile.close(); //close the file object.
			std::cout<<"total number of entries "<<total_entries<<std::endl;
  }
