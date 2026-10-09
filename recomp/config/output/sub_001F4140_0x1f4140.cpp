#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4140
// Address: 0x1f4140 - 0x1f4218
void sub_001F4140_0x1f4140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4140_0x1f4140");
#endif

    switch (ctx->pc) {
        case 0x1f416cu: goto label_1f416c;
        case 0x1f41f4u: goto label_1f41f4;
        default: break;
    }

    ctx->pc = 0x1f4140u;

    // 0x1f4140: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f4140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f4144: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4144u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f4148: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1f4148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1f414c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f414cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4150: 0xac20eaf0  sw          $zero, -0x1510($at)
    ctx->pc = 0x1f4150u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961904), GPR_U32(ctx, 0));
    // 0x1f4154: 0x2484eb00  addiu       $a0, $a0, -0x1500
    ctx->pc = 0x1f4154u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
    // 0x1f4158: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4158u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f415c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f415cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4160: 0x24060094  addiu       $a2, $zero, 0x94
    ctx->pc = 0x1f4160u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 148));
    // 0x1f4164: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F4164u;
    SET_GPR_U32(ctx, 31, 0x1F416Cu);
    ctx->pc = 0x1F4168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4164u;
            // 0x1f4168: 0xac20ec70  sw          $zero, -0x1390($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294962288), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F416Cu; }
        if (ctx->pc != 0x1F416Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F416Cu; }
        if (ctx->pc != 0x1F416Cu) { return; }
    }
    ctx->pc = 0x1F416Cu;
label_1f416c:
    // 0x1f416c: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1f416cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1f4170: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4170u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4174: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f4174u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f4178: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4178u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f417c: 0x8c22eb14  lw          $v0, -0x14EC($at)
    ctx->pc = 0x1f417cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961940)));
    // 0x1f4180: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1f4180u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1f4184: 0x41082a  slt         $at, $v0, $at
    ctx->pc = 0x1f4184u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1f4188: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F4188u;
    {
        const bool branch_taken_0x1f4188 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F418Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4188u;
            // 0x1f418c: 0x24020300  addiu       $v0, $zero, 0x300 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4188) {
            ctx->pc = 0x1F41A0u;
            goto label_1f41a0;
        }
    }
    ctx->pc = 0x1F4190u;
    // 0x1f4190: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1f4190u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1f4194: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4194u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4198: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f4198u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f419c: 0x24020300  addiu       $v0, $zero, 0x300
    ctx->pc = 0x1f419cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
label_1f41a0:
    // 0x1f41a0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41a4: 0xac22eb18  sw          $v0, -0x14E8($at)
    ctx->pc = 0x1f41a4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961944), GPR_U32(ctx, 2));
    // 0x1f41a8: 0x3c030036  lui         $v1, 0x36
    ctx->pc = 0x1f41a8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
    // 0x1f41ac: 0x2463efa0  addiu       $v1, $v1, -0x1060
    ctx->pc = 0x1f41acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963104));
    // 0x1f41b0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41b4: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f41b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f41b8: 0xac23eb1c  sw          $v1, -0x14E4($at)
    ctx->pc = 0x1f41b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961948), GPR_U32(ctx, 3));
    // 0x1f41bc: 0x2442ec90  addiu       $v0, $v0, -0x1370
    ctx->pc = 0x1f41bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962320));
    // 0x1f41c0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41c4: 0xac22eb24  sw          $v0, -0x14DC($at)
    ctx->pc = 0x1f41c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961956), GPR_U32(ctx, 2));
    // 0x1f41c8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41cc: 0x8c23eb1c  lw          $v1, -0x14E4($at)
    ctx->pc = 0x1f41ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961948)));
    // 0x1f41d0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41d4: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1f41d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1f41d8: 0x8c22eb24  lw          $v0, -0x14DC($at)
    ctx->pc = 0x1f41d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961956)));
    // 0x1f41dc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41e0: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f41e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f41e4: 0xac23eb20  sw          $v1, -0x14E0($at)
    ctx->pc = 0x1f41e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961952), GPR_U32(ctx, 3));
    // 0x1f41e8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41ec: 0xc042652  jal         func_109948
    ctx->pc = 0x1F41ECu;
    SET_GPR_U32(ctx, 31, 0x1F41F4u);
    ctx->pc = 0x1F41F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F41ECu;
            // 0x1f41f0: 0xac22eb28  sw          $v0, -0x14D8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294961960), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x109948u;
    if (runtime->hasFunction(0x109948u)) {
        auto targetFn = runtime->lookupFunction(0x109948u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F41F4u; }
        if (ctx->pc != 0x1F41F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00109948_0x109948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F41F4u; }
        if (ctx->pc != 0x1F41F4u) { return; }
    }
    ctx->pc = 0x1F41F4u;
label_1f41f4:
    // 0x1f41f4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41f8: 0xa022eb31  sb          $v0, -0x14CF($at)
    ctx->pc = 0x1f41f8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961969), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f41fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f41fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f4200: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4200u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4204: 0xa022eb38  sb          $v0, -0x14C8($at)
    ctx->pc = 0x1f4204u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961976), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4208: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1f4208u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f420c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f420cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4210: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4210u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4210u;
            // 0x1f4214: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4218u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
