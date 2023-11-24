#ifndef D_A_OBJ_SEARCH_H
#define D_A_OBJ_SEARCH_H

#include "f_op/f_op_actor.h"
#include "JSystem/J3DGraphAnimator/J3DNode.h"

namespace daObj_Search {
    class Act_c : public fopAc_ac_c {
    public:
        void getFindFlag() {}
        void isSecond() {}
        void modeProcInit(int) {}
        void setBkControl(bool) {}
        void setChildId(unsigned int) {}
        void setFindFlag(bool) {}
    
        void _createHeap();
        void searchCreateHeap();
        void beamCreateHeap(int);
        void _nodeControl(J3DNode*, J3DModel*);
        void modeSearchRndInit();
        void modeSearchRnd();
        void modeSearchPathInit();
        void modeSearchPath();
        void modeStopInit();
        void modeStop();
        void modeToSearchInit();
        void modeToSearch();
        void modeToStopInit();
        void modeToStop();
        void modeFindInit();
        void modeFind();
        void modeFind2ndInit();
        void modeFind2nd();
        void modeSearchBdkInit();
        void modeSearchBdk();
        void modeProc(daObj_Search::Act_c::Proc_e, int);
        void attr() const;
        void SetArgData();
        void CreateInit();
        void _create();
        void smoke_set(float, int);
        void _execute();
        void check_bk_control();
        void set_mtx_base();
        void set_mtx_light_A();
        void set_mtx_light_B();
        void set_moveBG_mtx_base();
        void set_moveBG_mtx_light_A();
        void set_moveBG_mtx_light_B();
        void bg_check();
        void player_check();
        void set_path_info();
        void is_path_info();
        void _draw();
        void _delete();
        void _isdelete();
    
    public:
        /* Place member variables here */
    };
};

#endif /* D_A_OBJ_SEARCH_H */