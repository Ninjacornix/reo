#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001408D8
// Address: 0x1408d8 - 0x1409e8
void sub_001408D8_0x1408d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001408D8_0x1408d8");
#endif

    switch (ctx->pc) {
        case 0x1409b0u: goto label_1409b0;
        case 0x1409c0u: goto label_1409c0;
        default: break;
    }

    ctx->pc = 0x1408d8u;

    // 0x1408d8: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x1408d8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1408dc: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1408dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1408e0: 0x80830001  lb          $v1, 0x1($a0)
    ctx->pc = 0x1408e0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1408e4: 0x24c698b0  addiu       $a2, $a2, -0x6750
    ctx->pc = 0x1408e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294940848));
    // 0x1408e8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1408e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1408ec: 0x80850002  lb          $a1, 0x2($a0)
    ctx->pc = 0x1408ecu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1408f0: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1408f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1408f4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1408f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1408f8: 0x8c490000  lw          $t1, 0x0($v0)
    ctx->pc = 0x1408f8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1408fc: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1408fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x140900: 0x8c670000  lw          $a3, 0x0($v1)
    ctx->pc = 0x140900u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140904: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x140904u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x140908: 0x80820003  lb          $v0, 0x3($a0)
    ctx->pc = 0x140908u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14090c: 0x91900  sll         $v1, $t1, 4
    ctx->pc = 0x14090cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x140910: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x140910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x140914: 0x674821  addu        $t1, $v1, $a3
    ctx->pc = 0x140914u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x140918: 0x8ca80000  lw          $t0, 0x0($a1)
    ctx->pc = 0x140918u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x14091c: 0x92900  sll         $a1, $t1, 4
    ctx->pc = 0x14091cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x140920: 0x80830004  lb          $v1, 0x4($a0)
    ctx->pc = 0x140920u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x140924: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x140924u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x140928: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x140928u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x14092c: 0xa84821  addu        $t1, $a1, $t0
    ctx->pc = 0x14092cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x140930: 0x8c470000  lw          $a3, 0x0($v0)
    ctx->pc = 0x140930u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x140934: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x140934u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x140938: 0x80820005  lb          $v0, 0x5($a0)
    ctx->pc = 0x140938u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14093c: 0x92900  sll         $a1, $t1, 4
    ctx->pc = 0x14093cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x140940: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x140940u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x140944: 0xa74821  addu        $t1, $a1, $a3
    ctx->pc = 0x140944u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x140948: 0x8c680000  lw          $t0, 0x0($v1)
    ctx->pc = 0x140948u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14094c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14094cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x140950: 0x80830006  lb          $v1, 0x6($a0)
    ctx->pc = 0x140950u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x140954: 0x92100  sll         $a0, $t1, 4
    ctx->pc = 0x140954u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x140958: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x140958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x14095c: 0x884821  addu        $t1, $a0, $t0
    ctx->pc = 0x14095cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
    // 0x140960: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x140960u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x140964: 0x91100  sll         $v0, $t1, 4
    ctx->pc = 0x140964u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x140968: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x140968u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14096c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x14096cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x140970: 0x454821  addu        $t1, $v0, $a1
    ctx->pc = 0x140970u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x140974: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x140974u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140978: 0x91100  sll         $v0, $t1, 4
    ctx->pc = 0x140978u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x14097c: 0x3e00008  jr          $ra
    ctx->pc = 0x14097Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14097Cu;
            // 0x140980: 0x441021  addu        $v0, $v0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1409B0u: goto label_1409b0;
            case 0x1409C0u: goto label_1409c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140984u;
    // 0x140984: 0x0  nop
    ctx->pc = 0x140984u;
    // NOP
    // 0x140988: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140988u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x14098c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x14098cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140990: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x140990u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140994: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140994u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140998: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x140998u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14099c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x14099cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1409a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1409a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1409a4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1409a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1409a8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1409A8u;
    SET_GPR_U32(ctx, 31, 0x1409B0u);
    ctx->pc = 0x1409ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1409A8u;
            // 0x1409ac: 0x8e060004  lw          $a2, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409B0u; }
        if (ctx->pc != 0x1409B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409B0u; }
        if (ctx->pc != 0x1409B0u) { return; }
    }
    ctx->pc = 0x1409B0u;
label_1409b0:
    // 0x1409b0: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1409b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1409b4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1409b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1409b8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1409B8u;
    SET_GPR_U32(ctx, 31, 0x1409C0u);
    ctx->pc = 0x1409BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1409B8u;
            // 0x1409bc: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409C0u; }
        if (ctx->pc != 0x1409C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409C0u; }
        if (ctx->pc != 0x1409C0u) { return; }
    }
    ctx->pc = 0x1409C0u;
label_1409c0:
    // 0x1409c0: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1409c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1409c4: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1409c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1409c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1409c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1409cc: 0x2484fff0  addiu       $a0, $a0, -0x10
    ctx->pc = 0x1409ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
    // 0x1409d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1409d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1409d4: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1409d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x1409d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1409d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1409dc: 0x8050210  j           func_140840
    ctx->pc = 0x1409DCu;
    ctx->pc = 0x1409E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1409DCu;
            // 0x1409e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140840u;
    if (runtime->hasFunction(0x140840u)) {
        auto targetFn = runtime->lookupFunction(0x140840u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00140840_0x140840(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1409E4u;
    // 0x1409e4: 0x0  nop
    ctx->pc = 0x1409e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
