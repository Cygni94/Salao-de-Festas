import _ from "lodash";

import {
    FETCH_CLIENTES,
    FETCH_CLIENTE,
    DELETE_CLIENTE,
    CREATE_CLIENTE,
} from "../actions/clientes";

const INITIAL_STATE = {};

export default function(state = INITIAL_STATE, action) {
    switch (action.type) {
        case FETCH_CLIENTES:
            const newClientes = _.mapKeys(action.payload.data, "id");
            return { ...state, ...newClientes };
        case CREATE_CLIENTE:
            return { ...state, [action.payload.data.id]: action.payload.data };
        case FETCH_CLIENTE:
            return { ...state, [action.payload.data.id]: action.payload.data };
        case DELETE_CLIENTE:
            return _.omit(state, action.payload.data.id);
        default:
            return state;
    }
}
