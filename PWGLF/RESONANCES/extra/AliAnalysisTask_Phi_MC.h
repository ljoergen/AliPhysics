// TODO LIST
// TODO: Add Invariant Mass to the Efficiency ( Migrate from canidate MC tree ? Add rec px, py, pz ? ) to check the Invariant Mass dependence of the Phi meson ( Rec (Gen IM) / Gen (Gen IM) ) not ( Rec (Rec IM) / Gen (Gen IM) )

#ifndef AliAnalysisTask_Phi_MC_H
#define AliAnalysisTask_Phi_MC_H

#include "AliAnalysisTaskSE.h"

class AliPIDResponse;
class AliAODTrack;

class
AliAnalysisTask_Phi_MC : public AliAnalysisTaskSE    {
    public:
    //
    // ---  Constructors
                                AliAnalysisTask_Phi_MC     ( );
                                AliAnalysisTask_Phi_MC     ( const char *      name );
    virtual                    ~AliAnalysisTask_Phi_MC     ( );
    //
    // ---  Required implementations
    virtual void                UserCreateOutputObjects     ( );
    virtual void                UserExec                    ( Option_t*         option );
    virtual void                Terminate                   ( Option_t*         option );
    //
    //  --- Not implemented
                                AliAnalysisTask_Phi_MC     ( const AliAnalysisTask_Phi_MC& );
    AliAnalysisTask_Phi_MC&    operator =                  ( const AliAnalysisTask_Phi_MC& );
    //
    //  --- Setters & Getters
    void                        SetSPCompute                ( Bool_t    SPFlag )            { kComputeSpherocity    = SPFlag; };
    void                        SetSPWighted                ( Bool_t    SPWeightFlag )      { kSpherocityPTWeight   = SPWeightFlag; };
    void                        SetRTCompute                ( Bool_t    RTFlag )            { kComputeRT            = RTFlag; };
    //
    private:
    //
    //  --- GENERAL --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
    //
    //  --- --- Functions
    bool                        fIsEventCandidate           ( );
    void                        fPostData                   ( );
    void                        fFillTrees                  ( );
    void                        uSetEventCountLabels        ( TH1D* );
    void                        uFillEventEnumerate         ( Int_t );
    void                        uFillEventEnumerate         ( TString );
    bool                        uIsEventMultiplicityAvailable ( );
    //
    //  --- --- Variables
    Bool_t                      kComputeSpherocity;         //  Spherocity Flag
    Bool_t                      kSpherocityPTWeight;        //  Spherocity PT Weighted Flag
    Bool_t                      kComputeRT;                 //  RT Flag
    Bool_t                      fIs_p_p;                    //! Collision system flag for pp
    Bool_t                      fIs_p_Pb;                   //! Collision system flag for pPb
    Bool_t                      fIs_Pb_Pb;                  //! Collision system flag for PbPb
    TString                     fRunName;                   //  MultiRun name
    TH1D*                       fQC_Event_Enum_FLL;         //! Event count utility histogram
    //
    //  --- EVENT --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
    //
    //  --- --- General Variables
    AliMCEvent*                 fMCD;                       //! input event MC
    TClonesArray*               AODMCTrackArray;            //! MC Tracks Array
    AliPPVsMultUtils*           fMultSelection;             //! Multiplicity Utility
    Float_t                     fCurrent_SPH;               //! Event Spherocity
    Float_t                     fCurrent_V0M;               //! Event V0M Multiplicity
    Float_t                     fCurrent_TRK;               //! Event Tracklets Multiplicity
    Float_t                     fCurrent_RT;                //! Event RTransverse
    Int_t                       fCurrent_Run;               //! Current Run Number
    UChar_t                     fTrueEventMask;             //! True Event Mask
    //
    //  --- --- Output Tree Variables
    TTree*                      tParticle_0333;             //! Output Tree for Signal
    Int_t                       fTNParticle_0333;           //! Number of Phis produced found
    Float_t                     fTPx          [2048];       //! Phi Px
    Float_t                     fTPy          [2048];       //! Phi Py
    Float_t                     fTPz          [2048];       //! Phi Pz
    //
    TList*                      lQCParticle_0333;           //! QC Histograms output list
    //
    TList*                      lAnalysisOutputList;        //! Analysis output list
    //
    ClassDef(AliAnalysisTask_Phi_MC, 1);
};

#endif
