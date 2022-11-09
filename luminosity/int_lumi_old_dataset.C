void int_lumi_old_dataset(TString chamber){

	 TCanvas *c_intlumi = new TCanvas("c_intlumi", "int lumi",800,600);
	 TCanvas *c_instlumi = new TCanvas("c_instlumi", "inst lumi",800,600);
//TString file_path  ="/cmsuf/data/store/user/t2/users/neha.rawal/CSCAgeing_newfiles/2017_again/final_files/2017/input_root_files/DUMMYFILENAME_2017_new_all_"+chamber+"_tree.root" ;
		TString file_path  = "/cmsuf/data/store/user/t2/users/neha.rawal/CSCAgeing_newfiles/2017_again/final_files/2017E/DUMMYFILENAME_all"+chamber+"_tree.root" ;
  TFile *file = TFile::Open(file_path);	
	TTree *tree =(TTree*)file->Get("tree");

  Double_t _integratelumi;
  Double_t _instlumi;
 	ULong64_t _runNb;
 	ULong64_t _eventNb;
	tree->SetBranchAddress("_integratelumi",&_integratelumi);
	tree->SetBranchAddress("_instlumi",&_instlumi);
	tree->SetBranchAddress("_runNb",&_runNb);
	tree->SetBranchAddress("_eventNb",&_eventNb);

	std::cout<<" tree entries "<<tree->GetEntries()<<std::endl;
	TH1D *hist_intlumi = new TH1D("hist_intlumi","integrated lumi ",45, 0,45);
	TH1D *hist_instlumi = new TH1D("hist_instlumi","inst lumi ",30, 0,15000);
	 for(int i=0; i<tree->GetEntries(); i++){
		 tree->GetEntry(i);
	   hist_intlumi->Fill(_integratelumi/1000.0);
	   hist_instlumi->Fill(_instlumi);
	 }

	 c_instlumi->cd();
	 hist_instlumi->Draw();
	 c_instlumi->SaveAs("instlumi_plots_old_E/instlumi_"+chamber+".pdf");

	 c_intlumi->cd();
	 hist_intlumi->Draw();
	 c_intlumi->SaveAs("intlumi_plots_old_E/intlumi_"+chamber+".pdf");


 std::cout<<"filled for 1 run"<<std::endl;
}
